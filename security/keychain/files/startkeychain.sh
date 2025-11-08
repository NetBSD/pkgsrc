#!/bin/sh

[ -n "$HOME" ] || HOME=$(getent passwd "$USER" | cut -d: -f6)

# Load user settings, if found.
[ -f "$HOME/.keychainrc" ] && . $HOME/.keychainrc

# If SSHKEYS is unset, search for private keys inside the ~/.ssh directory
[ -n "$SSHKEYS" ] || SSHKEYS=$(find ${HOME}/.ssh ! -name *pub \
				-exec grep -l -e '[DRS]S[AH] PRIVATE KEY' {} \; | tr '\n' ' ')
# If unset, keep GPGKEYS empty.
[ -n "$GPGKEYS" ] || GPGKEYS=""

# Allow to pass a number of keychain options as first argument.
# By deafult, use gpg2 and ensure that only the specified keys are loaded.

[ -n "$KCHOPTS" ] || KCHOPTS="--eval --gpg2"
case $1 in
    -f) KCHOPTS="$KCHOPTS --ssh-allow-forwarded" ;;
    -c) KCHOPTS="$KCHOPTS --clear" ;;
    -q) KCHOPTS="$KCHOPTS --quiet" ;;
    -h) echo "usage: keychain [-fcq]"
	exit 0 ;;
    -*|--*)
	echo "Unknown option $1"
	exit 2 ;;
esac

host	= $(uname -n)
ssh_env	= ${HOME}/.keychain/${host}-sh
gpg_env	= ${HOME}/.keychain/${host}-sh-gpg

# Test for SSHKEYS first. If empty, try GPGKEYS as fallback.
if [ -z "$SSHKEYS" ]; then
    printf '%s\n' "warning: no private keys found in $HOME/.ssh."
    if [ -n "$GPGKEYS" ]; then
	printf '%s\n' "Loading gpg key(s)"
	keychain $KCHOPTS $GPGKEYS
        [ -f "$gpg_env" ] && . $gpg_env
    else
	# Error out if no loadable keys were specified.
	printf '%s\n' "warning: empty gpg keys list." \
	"Use the SSHKEYS and GPGKEYS envinromental variables to specify one or more key to load."
	exit 1
    fi
else
# Otherwise load both SSHKEYS and GPGKEYS (allow the latter to be empty).
    keychain $KCHOPTS $SSHKEYS $GPGKEYS
    for file in ssh_env gpg_env; do
	[ -f "$file" ] && . $file
    done
fi

unset KCHOPTS SSHKEYS GPGKEYS host
