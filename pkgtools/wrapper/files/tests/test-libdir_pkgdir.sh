# $NetBSD: test-libdir_pkgdir.sh,v 1.1.2.2 2008/07/13 20:40:28 schmonz Exp $
#

atf_test_case libdir_pkgdir
libdir_pkgdir_head() {
    atf_set 'descr' 'XXX autoconverted from libdir-pkgdir.mk'
}
libdir_pkgdir_body() {
    input="-L${LOCALBASE}/lib"
    echo "-L${BUILDLINK_DIR}/lib" > expout
    atf_check 'echowrapper ${input}' 0 expout ignore
}

atf_test_case libdir_pkgdir_slashdot
libdir_pkgdir_slashdot_head() {
    atf_set 'descr' 'XXX autoconverted from libdir-pkgdir-slashdot.mk'
}
libdir_pkgdir_slashdot_body() {
    input="-L${LOCALBASE}/lib/."
    echo "-L${BUILDLINK_DIR}/lib" > expout
    atf_check 'echowrapper ${input}' 0 expout ignore
}

atf_test_case libdir_pkgsubdir
libdir_pkgsubdir_head() {
    atf_set 'descr' 'XXX autoconverted from libdir-pkgsubdir.mk'
}
libdir_pkgsubdir_body() {
    input="-L${LOCALBASE}/lib/mysql"
    echo "-L${BUILDLINK_DIR}/lib/mysql" > expout
    atf_check 'echowrapper ${input}' 0 expout ignore
}

atf_init_test_cases() {
    atf_add_test_case libdir_pkgdir
    atf_add_test_case libdir_pkgdir_slashdot
    atf_add_test_case libdir_pkgsubdir
}
