# $NetBSD: test-include_pkgdir.sh,v 1.1.2.1 2008/07/13 18:47:59 schmonz Exp $
#

atf_test_case include_pkgdir
include_pkgdir_head() {
    atf_set 'descr' 'XXX autoconverted from include-pkgdir.mk'
}
include_pkgdir_body() {
    input="-I${LOCALBASE}/include"
    echo "-I${BUILDLINK_DIR}/include" > expout
    atf_check 'echowrapper ${input}' 0 expout ignore
}

atf_init_test_cases() {
    atf_add_test_case include_pkgdir
}
