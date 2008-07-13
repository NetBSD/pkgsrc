# $NetBSD: test-libpath.sh,v 1.1.2.1 2008/07/13 18:47:59 schmonz Exp $
#

atf_test_case libpath
libpath_head() {
    atf_set 'descr' 'XXX autoconverted from libpath.mk'
}
libpath_body() {
    input="${LOCALBASE}/lib/libfoo.la"
    echo "${BUILDLINK_DIR}/lib/libfoo.la" > expout
    atf_check 'echowrapper ${input}' 0 expout ignore
}

atf_init_test_cases() {
    atf_add_test_case libpath
}
