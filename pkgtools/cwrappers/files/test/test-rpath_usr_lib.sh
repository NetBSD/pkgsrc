# $NetBSD: test-rpath_usr_lib.sh,v 1.1 2014/09/17 12:40:56 joerg Exp $
#

atf_test_case rpath_usr_lib
rpath_usr_lib_head() {
    atf_set 'descr' 'XXX autoconverted from rpath-usr-lib.mk'
}
rpath_usr_lib_body() {
    wrapper_test_setup cc
    input="${COMPILER_RPATH_FLAG}/usr/lib"
    echo > expout
    atf-check -s eq:0 -o file:expout -e ignore ${WRAPPER} ${input} \
	|| atf_fail 'XXX no reason'
}

atf_test_case rpath_usr_lib_slashdot
rpath_usr_lib_slashdot_head() {
    atf_set 'descr' 'XXX autoconverted from rpath-usr-lib-slashdot.mk'
}
rpath_usr_lib_slashdot_body() {
    wrapper_test_setup cc
    input="${COMPILER_RPATH_FLAG}/usr/lib/."
    echo > expout
    atf-check -s eq:0 -o file:expout -e ignore ${WRAPPER} ${input} \
	|| atf_fail 'XXX no reason'
}

atf_test_case rpath_usr_lib_subdir
rpath_usr_lib_subdir_head() {
    atf_set 'descr' 'XXX autoconverted from rpath-usr-lib-subdir.mk'
}
rpath_usr_lib_subdir_body() {
    wrapper_test_setup cc
    input="${COMPILER_RPATH_FLAG}/usr/lib/i18n"
    case "${_USE_RPATH}" in	# XXX do we want this?
    [yY][eE][sS])
        echo "${COMPILER_RPATH_FLAG}/usr/lib/i18n" > expout
        ;;
    *)
        echo > expout
        ;;
    esac
    atf-check -s eq:0 -o file:expout -e ignore ${WRAPPER} ${input} \
	|| atf_fail 'XXX no reason'
}

atf_init_test_cases() {
    . $(atf_get_srcdir)/setup_common.sh
    atf_add_test_case rpath_usr_lib
    atf_add_test_case rpath_usr_lib_slashdot
    atf_add_test_case rpath_usr_lib_subdir
}
