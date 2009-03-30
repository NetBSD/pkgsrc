# $NetBSD: test-lib_expand.sh,v 1.1.2.3 2009/03/30 01:02:26 schmonz Exp $
#

atf_test_case lib_expand
lib_expand_head() {
    atf_set 'descr' 'Checks that one -llib can be expanded into several'
}
lib_expand_body() {
    input="-lreadline -lreadline"
    echo "-ledit -ltermcap -lm" > expout
    atf-check -s eq:0 -o file:expout e ignore 'echowrapper ${input}'
}

atf_init_test_cases() {
    atf_add_test_case lib_expand
}
