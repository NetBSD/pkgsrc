atf_test_case libexpand
libexpand_head() {
    atf_set 'descr' 'Checks that one -llib can be expanded into several'
}
libexpand_body() {
    input='-lreadline'
    echo '-ledit -ltermcap -lm' > expout
    atf_check "echowrapper ${input}" 0 expout ignore
}

atf_init_test_cases() {
    atf_add_test_case libexpand
}
