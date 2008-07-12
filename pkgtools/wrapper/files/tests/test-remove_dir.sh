# $NetBSD: test-remove_dir.sh,v 1.1.2.1 2008/07/12 06:57:49 schmonz Exp $
#

atf_test_case removedir
removedir_head() {
    atf_set 'descr' 'Checks that undesirable link/include dirs are removed'
}
removedir_body() {
    input='-L/opt/schily/lib -I/opt/schily/include'
    echo > expout
    atf_check 'echowrapper ${input}' 0 expout ignore
}

atf_init_test_cases() {
    atf_add_test_case removedir
}
