# $NetBSD: test-libdir_usr_lib_subdir.sh,v 1.1.2.1 2008/07/13 18:47:59 schmonz Exp $
#

atf_test_case libdir_usr_lib_subdir
libdir_usr_lib_subdir_head() {
    atf_set 'descr' 'XXX autoconverted from libdir-usr-lib-subdir.mk'
}
libdir_usr_lib_subdir_body() {
    input="-L/usr/lib/i18n"
    echo "-L/usr/lib/i18n" > expout
    atf_check 'echowrapper ${input}' 0 expout ignore
}

atf_init_test_cases() {
    atf_add_test_case libdir_usr_lib_subdir
}
