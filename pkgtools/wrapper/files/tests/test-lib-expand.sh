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
