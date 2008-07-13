# $NetBSD: test-remove_option.sh,v 1.1.2.1 2008/07/13 18:47:59 schmonz Exp $
#

atf_test_case remove_option
remove_option_head() {
    atf_set 'descr' 'XXX autoconverted from remove-option.mk'
}
remove_option_body() {
    input="-O2 -O5 -O9"
    echo "" > expout
    atf_check 'echowrapper ${input}' 0 expout ignore
}

atf_init_test_cases() {
    atf_add_test_case remove_option
}
