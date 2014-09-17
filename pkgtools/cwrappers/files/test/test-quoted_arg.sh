# $NetBSD: test-quoted_arg.sh,v 1.1 2014/09/17 12:40:56 joerg Exp $
#

atf_test_case quoted_arg
quoted_arg_head() {
    atf_set 'descr' 'Checks that quoted arguments pass unmolested'
}
quoted_arg_body() {
    wrapper_test_setup cc
    input='-D"DEFAULT_MODULE_PATH=\"${LOCALBASE}/lib/security/\""'
    echo "${input}" > expout
    atf-check -s eq:0 -o file:expout -e ignore ${WRAPPER} ${input} \
	|| atf_fail 'XXX no reason'
}

atf_init_test_cases() {
    . $(atf_get_srcdir)/setup_common.sh
    atf_add_test_case quoted_arg
}
