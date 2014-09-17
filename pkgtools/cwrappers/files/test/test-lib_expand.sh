# $NetBSD: test-lib_expand.sh,v 1.1 2014/09/17 12:40:56 joerg Exp $
#

atf_test_case lib_expand
lib_expand_head() {
    atf_set 'descr' 'Checks that one -llib can be expanded into several'
}
lib_expand_body() {
    wrapper_test_setup cc \
	l:readline:edit:termcap:m
    input="-lreadline -lreadline"
    echo "-ledit -ltermcap -lm" > expout
    atf-check -s eq:0 -o file:expout -e ignore ${WRAPPER} ${input} \
	|| atf_fail 'XXX no reason'
}

atf_init_test_cases() {
    . $(atf_get_srcdir)/setup_common.sh
    atf_add_test_case lib_expand
}
