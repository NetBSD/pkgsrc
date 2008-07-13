# $NetBSD: test-rpath_usr_lib_subdir.sh,v 1.1.2.1 2008/07/13 20:10:37 schmonz Exp $
#

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
    atf_add_test_case rpath_usr_lib_subdir
}
