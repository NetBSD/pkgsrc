# $NetBSD: test-include_pkgsubdir.sh,v 1.1.2.1 2008/07/13 18:47:59 schmonz Exp $
#

atf_test_case include_pkgsubdir
include_pkgsubdir_head() {
    atf_set 'descr' 'XXX autoconverted from include-pkgsubdir.mk'
}
include_pkgsubdir_body() {
    input="-I${LOCALBASE}/include/krb5"
    echo "-I${BUILDLINK_DIR}/include/krb5" > expout
    atf_check 'echowrapper ${input}' 0 expout ignore
}

atf_init_test_cases() {
    atf_add_test_case include_pkgsubdir
}
