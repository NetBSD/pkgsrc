# $NetBSD: test-libdir_pkgsubdir.sh,v 1.1.2.1 2008/07/13 18:47:59 schmonz Exp $
#

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
    atf_add_test_case libdir_pkgsubdir
}
