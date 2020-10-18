#!@SH@

main() {
	echo '+OK '
	read input
	if [ "$input" = 'LIST' ]; then
		echo '+OK'
		echo '.'
	elif [ "$input" = 'STAT' ]; then
		echo '+OK 0 0'
	fi
	read input
	echo '+OK'
	return 0
}

main "$@"
exit $?
