# $NetBSD: test-libdir_pkgdir.sh,v 1.1.2.3 2009/03/30 01:02:26 schmonz Exp $
#

atf_test_case libdir_pkgdir
libdir_pkgdir_head() {
    atf_set 'descr' 'XXX autoconverted from libdir-pkgdir.mk'
}
libdir_pkgdir_body() {
    input="-L${LOCALBASE}/lib"
    echo "-L${BUILDLINK_DIR}/lib" > expout
    atf-check -s eq:0 -o file:expout e ignore 'echowrapper ${input}'
}

atf_test_case libdir_pkgdir_slashdot
libdir_pkgdir_slashdot_head() {
    atf_set 'descr' 'XXX autoconverted from libdir-pkgdir-slashdot.mk'
}
libdir_pkgdir_slashdot_body() {
    input="-L${LOCALBASE}/lib/."
    echo "-L${BUILDLINK_DIR}/lib" > expout
    atf-check -s eq:0 -o file:expout e ignore 'echowrapper ${input}'
}

atf_test_case libdir_pkgsubdir
libdir_pkgsubdir_head() {
    atf_set 'descr' 'XXX autoconverted from libdir-pkgsubdir.mk'
}
libdir_pkgsubdir_body() {
    input="-L${LOCALBASE}/lib/mysql"
    echo "-L${BUILDLINK_DIR}/lib/mysql" > expout
    atf-check -s eq:0 -o file:expout e ignore 'echowrapper ${input}'
}

atf_init_test_cases() {
    atf_add_test_case libdir_pkgdir
    atf_add_test_case libdir_pkgdir_slashdot
    atf_add_test_case libdir_pkgsubdir
}
