# $NetBSD: test-include_pkgdir.sh,v 1.1.2.2 2008/07/13 20:40:28 schmonz Exp $
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

atf_test_case include_pkgdir_slashdot
include_pkgdir_slashdot_head() {
    atf_set 'descr' 'Checks that trailing /. is elided from includes'
}
include_pkgdir_slashdot_body() {
    input="-I${LOCALBASE}/include/."
    echo "-I${BUILDLINK_DIR}/include" > expout
    atf_check 'echowrapper ${input}' 0 expout ignore
}

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
    atf_add_test_case include_pkgdir
    atf_add_test_case include_pkgdir_slashdot
    atf_add_test_case include_pkgsubdir
}
