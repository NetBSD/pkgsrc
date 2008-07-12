# $NetBSD: test-include_pkgdir_slashdot.sh,v 1.1.2.2 2008/07/12 06:57:49 schmonz Exp $
#

atf_test_case include_pkgdir_slashdot
include_pkgdir_slashdot_head() {
    atf_set 'descr' 'Checks that trailing /. is elided from includes'
}
include_pkgdir_slashdot_body() {
    input="-I${LOCALBASE}/include/."
    echo "-I${BUILDLINK_DIR}/include" > expout
    atf_check 'echowrapper ${input}' 0 expout ignore
}

atf_init_test_cases() {
    atf_add_test_case include_pkgdir_slashdot
}
