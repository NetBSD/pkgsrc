# $NetBSD: test-libpath_shlib.sh,v 1.1.2.1 2008/07/13 18:47:59 schmonz Exp $
#

atf_test_case libpath_shlib
libpath_shlib_head() {
    atf_set 'descr' 'XXX autoconverted from libpath-shlib.mk'
}
libpath_shlib_body() {
    input="${LOCALBASE}/lib/libfoo.so"
    echo "-L${BUILDLINK_DIR}/lib -lfoo" > expout
    atf_check 'echowrapper ${input}' 0 expout ignore
}

atf_init_test_cases() {
    atf_add_test_case libpath_shlib
}
