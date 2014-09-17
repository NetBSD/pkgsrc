# $NetBSD: test-no_abspath.sh,v 1.1 2014/09/17 12:40:56 joerg Exp $
#

atf_test_case no_abspath
no_abspath_head() {
    atf_set 'descr' 'XXX autoconverted from no-abspath.mk'
}
no_abspath_body() {
    wrapper_test_setup cc
    input="-L/bad/path/lib -I/bad/path/include ${COMPILER_RPATH_FLAG}/bad/path/lib"
    echo > expout
    atf-check -s eq:0 -o file:expout -e ignore ${WRAPPER} ${input} \
	|| atf_fail 'XXX no reason'
}

atf_init_test_cases() {
    . $(atf_get_srcdir)/setup_common.sh
    atf_add_test_case no_abspath
}
