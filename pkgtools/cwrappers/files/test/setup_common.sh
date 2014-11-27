wrapper_test_setup() {
    local _wrappee
    _wrappee=$1; shift

    # variables available to tests
    WRAPPER="$(atf_get_srcdir)/../bin/${_wrappee}-wrapper"
    CWRAPPERS_CONFIG_DIR=wrapperconfig; export CWRAPPERS_CONFIG_DIR
    mkdir ${CWRAPPERS_CONFIG_DIR}
    LOCALBASE=/local/base
    BUILDLINK_DIR=/wrksrc/build/link
    COMPILER_RPATH_FLAG="-Wl,-R"	# or -L on Darwin, or...

    # minimal config file for test purposes
    cat > ${CWRAPPERS_CONFIG_DIR}/${_wrappee} << EOF
worklog=/dev/null
exec=echo
transform=I:${LOCALBASE}:${BUILDLINK_DIR}
EOF
    # plus any requested transforms
    while [ $# -gt 0 ]; do
	echo "transform=$1" >> ${CWRAPPERS_CONFIG_DIR}/${_wrappee}
	shift
    done

}
