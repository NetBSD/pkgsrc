# $NetBSD: test-libpath_shmod.sh,v 1.1.2.1 2008/07/13 18:47:59 schmonz Exp $
#

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
    atf_add_test_case libpath_shmod
}
