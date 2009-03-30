# $NetBSD: test-include_pkgdir.sh,v 1.1.2.3 2009/03/30 01:02:26 schmonz Exp $
#

atf_test_case include_pkgdir
include_pkgdir_head() {
    atf_set 'descr' 'XXX autoconverted from include-pkgdir.mk'
}
include_pkgdir_body() {
    input="-I${LOCALBASE}/include"
    echo "-I${BUILDLINK_DIR}/include" > expout
    atf-check -s eq:0 -o file:expout e ignore 'echowrapper ${input}'
}

atf_test_case include_pkgdir_slashdot
include_pkgdir_slashdot_head() {
    atf_set 'descr' 'Checks that trailing /. is elided from includes'
}
include_pkgdir_slashdot_body() {
    input="-I${LOCALBASE}/include/."
    echo "-I${BUILDLINK_DIR}/include" > expout
    atf-check -s eq:0 -o file:expout e ignore 'echowrapper ${input}'
}

atf_test_case include_pkgsubdir
include_pkgsubdir_head() {
    atf_set 'descr' 'XXX autoconverted from include-pkgsubdir.mk'
}
include_pkgsubdir_body() {
    input="-I${LOCALBASE}/include/krb5"
    echo "-I${BUILDLINK_DIR}/include/krb5" > expout
    atf-check -s eq:0 -o file:expout e ignore 'echowrapper ${input}'
}

atf_init_test_cases() {
    atf_add_test_case include_pkgdir
    atf_add_test_case include_pkgdir_slashdot
    atf_add_test_case include_pkgsubdir
}
