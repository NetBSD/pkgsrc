# $NetBSD: test-lib_expand.sh,v 1.1.2.1 2008/07/12 06:57:49 schmonz Exp $
#

atf_test_case lib_expand
lib_expand_head() {
    atf_set 'descr' 'Checks that one -llib can be expanded into several'
}
lib_expand_body() {
    input='-lreadline'
    echo '-ledit -ltermcap -lm' > expout
    atf_check 'echowrapper ${input}' 0 expout ignore
}

atf_init_test_cases() {
    atf_add_test_case lib_expand
}
