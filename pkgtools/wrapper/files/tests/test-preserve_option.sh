# $NetBSD: test-preserve_option.sh,v 1.1.2.1 2008/07/13 18:47:59 schmonz Exp $
#

atf_test_case preserve_option
preserve_option_head() {
    atf_set 'descr' 'XXX autoconverted from preserve-option.mk'
}
preserve_option_body() {
    input="-O2ABC"
    echo "-O2ABC" > expout
    atf_check 'echowrapper ${input}' 0 expout ignore
}

atf_init_test_cases() {
    atf_add_test_case preserve_option
}
