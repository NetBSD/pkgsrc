# $NetBSD: test-libpath_in_define.sh,v 1.1.2.1 2008/07/13 18:47:59 schmonz Exp $
#

atf_test_case libpath_in_define
libpath_in_define_head() {
    atf_set 'descr' 'XXX autoconverted from libpath-in-define.mk'
}
libpath_in_define_body() {
    input="-DFOO=\"${LOCALBASE}/lib/libfoo.la\""
    echo "-DFOO=\"${LOCALBASE}/lib/libfoo.la\"" > expout
    atf_check 'echowrapper ${input}' 0 expout ignore
}

atf_init_test_cases() {
    atf_add_test_case libpath_in_define
}
