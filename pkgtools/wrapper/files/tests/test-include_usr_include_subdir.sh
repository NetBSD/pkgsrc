# $NetBSD: test-include_usr_include_subdir.sh,v 1.1.2.1 2008/07/13 18:47:59 schmonz Exp $
#

atf_test_case include_usr_include_subdir
include_usr_include_subdir_head() {
    atf_set 'descr' 'XXX autoconverted from include-usr-include-subdir.mk'
}
include_usr_include_subdir_body() {
    input="-I/usr/include/krb5"
    echo "-I/usr/include/krb5" > expout
    atf_check 'echowrapper ${input}' 0 expout ignore
}

atf_init_test_cases() {
    atf_add_test_case include_usr_include_subdir
}
