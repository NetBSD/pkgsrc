# $NetBSD: test-libpath.sh,v 1.1.2.2 2008/07/13 20:40:28 schmonz Exp $
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

atf_test_case libpath_in_define
libpath_in_define_head() {
    atf_set 'descr' 'XXX autoconverted from libpath-in-define.mk'
}
libpath_in_define_body() {
    input="-DFOO=\"${LOCALBASE}/lib/libfoo.la\""
    echo "-DFOO=\"${LOCALBASE}/lib/libfoo.la\"" > expout
    atf_check 'echowrapper ${input}' 0 expout ignore
}

atf_test_case libpath_shlib
libpath_shlib_head() {
    atf_set 'descr' 'XXX autoconverted from libpath-shlib.mk'
}
libpath_shlib_body() {
    input="${LOCALBASE}/lib/libfoo.so"
    echo "-L${BUILDLINK_DIR}/lib -lfoo" > expout
    atf_check 'echowrapper ${input}' 0 expout ignore
}

atf_test_case libpath_shmod
libpath_shmod_head() {
    atf_set 'descr' 'XXX autoconverted from libpath-shmod.mk'
}
libpath_shmod_body() {
    input="${LOCALBASE}/lib/module/foo.so"
    echo "${LOCALBASE}/lib/module/foo.so" > expout
    atf_check 'echowrapper ${input}' 0 expout ignore
}

atf_init_test_cases() {
    atf_add_test_case libpath
    atf_add_test_case libpath_in_define
    atf_add_test_case libpath_shlib
    atf_add_test_case libpath_shmod
}
