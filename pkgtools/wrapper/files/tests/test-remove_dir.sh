# $NetBSD: test-remove_dir.sh,v 1.1.2.2 2008/07/13 18:36:31 schmonz Exp $
#

atf_test_case remove_dir
remove_dir_head() {
    atf_set 'descr' 'Checks that undesirable link/include dirs are removed'
}
remove_dir_body() {
    input="-L/opt/schily/lib -I/opt/schily/include"
    echo > expout
    atf_check 'echowrapper ${input}' 0 expout ignore
}

atf_init_test_cases() {
    atf_add_test_case remove_dir
}
