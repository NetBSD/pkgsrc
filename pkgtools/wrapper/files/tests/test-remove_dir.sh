# $NetBSD: test-remove_dir.sh,v 1.1.2.3 2009/03/30 01:02:26 schmonz Exp $
#

atf_test_case remove_dir
remove_dir_head() {
    atf_set 'descr' 'Checks that undesirable link/include dirs are removed'
}
remove_dir_body() {
    input="-L/opt/schily/lib -I/opt/schily/include"
    echo > expout
    atf-check -s eq:0 -o file:expout e ignore 'echowrapper ${input}'
}

atf_init_test_cases() {
    atf_add_test_case remove_dir
}
