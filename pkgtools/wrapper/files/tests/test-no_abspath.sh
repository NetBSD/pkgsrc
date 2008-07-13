# $NetBSD: test-no_abspath.sh,v 1.1.2.1 2008/07/13 18:47:59 schmonz Exp $
#

atf_test_case no_abspath
no_abspath_head() {
    atf_set 'descr' 'XXX autoconverted from no-abspath.mk'
}
no_abspath_body() {
    input="-L/bad/path/lib -I/bad/path/include ${COMPILER_RPATH_FLAG}/bad/path/lib"
    echo "" > expout
    atf_check 'echowrapper ${input}' 0 expout ignore
}

atf_init_test_cases() {
    atf_add_test_case no_abspath
}
