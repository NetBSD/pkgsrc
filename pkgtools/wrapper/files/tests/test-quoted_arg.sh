# $NetBSD: test-quoted_arg.sh,v 1.1.2.3 2009/03/30 01:02:26 schmonz Exp $
#

atf_test_case quoted_arg
quoted_arg_head() {
    atf_set 'descr' 'Checks that quoted arguments pass unmolested'
}
quoted_arg_body() {
    input='-D"DEFAULT_MODULE_PATH=\"${LOCALBASE}/lib/security/\""'
    echo "${input}" > expout
    atf-check -s eq:0 -o file:expout e ignore 'echowrapper ${input}'
}

atf_init_test_cases() {
    atf_add_test_case quoted_arg
}
