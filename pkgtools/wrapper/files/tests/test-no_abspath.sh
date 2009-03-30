# $NetBSD: test-no_abspath.sh,v 1.1.2.3 2009/03/30 01:02:26 schmonz Exp $
#

atf_test_case no_abspath
no_abspath_head() {
    atf_set 'descr' 'XXX autoconverted from no-abspath.mk'
}
no_abspath_body() {
    input="-L/bad/path/lib -I/bad/path/include ${COMPILER_RPATH_FLAG}/bad/path/lib"
    echo > expout
    atf-check -s eq:0 -o file:expout e ignore 'echowrapper ${input}'
}

atf_init_test_cases() {
    atf_add_test_case no_abspath
}
