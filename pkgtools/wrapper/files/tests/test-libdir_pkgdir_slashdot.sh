# $NetBSD: test-libdir_pkgdir_slashdot.sh,v 1.1.2.1 2008/07/13 18:47:59 schmonz Exp $
#

atf_test_case libdir_pkgdir_slashdot
libdir_pkgdir_slashdot_head() {
    atf_set 'descr' 'XXX autoconverted from libdir-pkgdir-slashdot.mk'
}
libdir_pkgdir_slashdot_body() {
    input="-L${LOCALBASE}/lib/."
    echo "-L${BUILDLINK_DIR}/lib" > expout
    atf_check 'echowrapper ${input}' 0 expout ignore
}

atf_init_test_cases() {
    atf_add_test_case libdir_pkgdir_slashdot
}
