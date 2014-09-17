# $NetBSD: test-remove_dir.sh,v 1.1 2014/09/17 12:40:56 joerg Exp $
#

atf_test_case remove_dir
remove_dir_head() {
    atf_set 'descr' 'Checks that undesirable link/include dirs are removed'
}
remove_dir_body() {
    wrapper_test_setup cc
    input="-L/opt/schily/lib -I/opt/schily/include"
    echo > expout
    atf-check -s eq:0 -o file:expout -e ignore ${WRAPPER} ${input} \
	|| atf_fail 'XXX no reason'
}

atf_init_test_cases() {
    . $(atf_get_srcdir)/setup_common.sh
    atf_add_test_case remove_dir
}
