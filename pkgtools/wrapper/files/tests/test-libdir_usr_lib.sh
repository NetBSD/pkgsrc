# $NetBSD: test-libdir_usr_lib.sh,v 1.1.2.4 2009/03/30 01:02:26 schmonz Exp $
#

atf_test_case libdir_usr_lib
libdir_usr_lib_head() {
    atf_set 'descr' 'XXX autoconverted from libdir-usr-lib.mk'
}
libdir_usr_lib_body() {
    input="-L/usr/lib"
    echo > expout
    atf-check -s eq:0 -o file:expout e ignore 'echowrapper ${input}'
}

atf_test_case libdir_usr_lib_slashdot
libdir_usr_lib_slashdot_head() {
    atf_set 'descr' 'XXX autoconverted from libdir-usr-lib-slashdot.mk'
}
libdir_usr_lib_slashdot_body() {
    input="-L/usr/lib/."
    echo > expout
    atf-check -s eq:0 -o file:expout e ignore 'echowrapper ${input}'
}

atf_test_case libdir_usr_lib_subdir
libdir_usr_lib_subdir_head() {
    atf_set 'descr' 'XXX autoconverted from libdir-usr-lib-subdir.mk'
}
libdir_usr_lib_subdir_body() {
    input="-L/usr/lib/i18n"
    echo "-L/usr/lib/i18n" > expout
    atf-check -s eq:0 -o file:expout e ignore 'echowrapper ${input}'
}

atf_init_test_cases() {
    atf_add_test_case libdir_usr_lib
    atf_add_test_case libdir_usr_lib_slashdot
    atf_add_test_case libdir_usr_lib_subdir
}
