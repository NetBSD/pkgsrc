#
# Wrapper for the SunOS builtin krb5-config, which does not accept all of the
# 'libraries' arguments that the standard MIT krb5-config does.
#

args=
for arg; do
	case "${arg}" in
	# Unsupported arguments
	gssapi|kadm-client|kadm-server|kdb)
		continue
		;;
	*)
		args="${args} ${arg}"
		;;
	esac
done

@KRB5_CONFIG@ ${args}
