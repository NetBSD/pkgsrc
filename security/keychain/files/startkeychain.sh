#!/bin/sh

[ -n "$HOME" ] || HOME=$(getent passwd "$USER" | cut -d: -f6)

[ -n "$HOSTNAME" ] || HOSTNAME=$(uname -n)

# Load user settings, if found.
[ -f "$HOME/.keychainrc" ] && . $HOME/.keychainrc

# If SSHKEYS is unset, search for private keys inside the ~/.ssh directory.
[ -n "$SSHKEYS" ] || SSHKEYS=$(find ${HOME}/.ssh ! -name *pub \
				-exec grep -l -e '[DRS]S[AH] PRIVATE KEY' {} \; | tr '\n' ' ')
# If unset, keep GPGKEYS empty.
[ -n "$GPGKEYS" ] || GPGKEYS=""

# Allow to pass some keychain options as argument.
# Silence output by default, to allow this to be sourced in login scripts.
[ -n "$KCHOPTS" ] || KCHOPTS="--quiet"
case $1 in
    -c) KCHOPTS="$KCHOPTS --clear" ;;
    -e) KCHOPTS="$KCHOPTS --eval" ;;
    -f) KCHOPTS="$KCHOPTS --ssh-allow-forwarded" ;;
    -h) echo "usage: keychain [-fcq]"
        exit 0 ;;
    -*|--*)
        echo "Unknown option $1"
        exit 2 ;;
esac

# Files where keychain stores the updated environment for SSH and - 
# GPG agents. 
ssh_env="${HOME}/.keychain/${HOSTNAME}-sh"
gpg_env="${HOME}/.keychain/${HOSTNAME}-sh-gpg"

[ -n "$SSHKEYS" ] || printf '%s\n' "warning: no private keys found in $HOME/.ssh."

if [ -z "$SSHKEYS" ] && [ -z "$GPGKEYS" ]; then
    # Error out if no loadable keys were specified.
    printf '%s\n' "error: no key id provided" \
    "Use the SSHKEYS and GPGKEYS envinromental variables to specify one or more key to load."
    exit 1
else
    # Otherwise load both SSHKEYS and GPGKEYS.
    keychain $KCHOPTS $SSHKEYS $GPGKEYS
    # Update environment. NOTE: This will only work if startkeychain is -
    # sourced within a shell start-up script.
    for file in "$ssh_env" "$gpg_env"; do
        [ -f "$file" ] && . $file
    done

fi

unset KCHOPTS SSHKEYS GPGKEYS
