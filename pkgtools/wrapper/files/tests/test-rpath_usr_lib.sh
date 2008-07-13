# $NetBSD: test-rpath_usr_lib.sh,v 1.1.2.3 2008/07/13 20:40:28 schmonz Exp $
#

atf_test_case rpath_usr_lib
rpath_usr_lib_head() {
    atf_set 'descr' 'XXX autoconverted from rpath-usr-lib.mk'
}
rpath_usr_lib_body() {
    input="${COMPILER_RPATH_FLAG}/usr/lib"
    echo > expout
    atf_check 'echowrapper ${input}' 0 expout ignore
}

atf_test_case rpath_usr_lib_slashdot
rpath_usr_lib_slashdot_head() {
    atf_set 'descr' 'XXX autoconverted from rpath-usr-lib-slashdot.mk'
}
rpath_usr_lib_slashdot_body() {
    input="${COMPILER_RPATH_FLAG}/usr/lib/."
    echo > expout
    atf_check 'echowrapper ${input}' 0 expout ignore
}

atf_test_case rpath_usr_lib_subdir
rpath_usr_lib_subdir_head() {
    atf_set 'descr' 'XXX autoconverted from rpath-usr-lib-subdir.mk'
}
rpath_usr_lib_subdir_body() {
    input="${COMPILER_RPATH_FLAG}/usr/lib/i18n"
    case "${_USE_RPATH}" in
    [yY][eE][sS])
        echo "${COMPILER_RPATH_FLAG}/usr/lib/i18n"
        ;;
    *)
        echo > expout
        ;;
    esac
    atf_check 'echowrapper ${input}' 0 expout ignore
}

atf_init_test_cases() {
    atf_add_test_case rpath_usr_lib
    atf_add_test_case rpath_usr_lib_slashdot
    atf_add_test_case rpath_usr_lib_subdir
}
