# $NetBSD: test-libdir_usr_lib.sh,v 1.1 2014/09/17 12:40:56 joerg Exp $
#

atf_test_case libdir_usr_lib
libdir_usr_lib_head() {
    atf_set 'descr' 'XXX autoconverted from libdir-usr-lib.mk'
}
libdir_usr_lib_body() {
    wrapper_test_setup cc
    input="-L/usr/lib"
    echo > expout
    atf-check -s eq:0 -o file:expout -e ignore ${WRAPPER} ${input} \
	|| atf_fail 'XXX no reason'
}

atf_test_case libdir_usr_lib_slashdot
libdir_usr_lib_slashdot_head() {
    atf_set 'descr' 'XXX autoconverted from libdir-usr-lib-slashdot.mk'
}
libdir_usr_lib_slashdot_body() {
    wrapper_test_setup cc
    input="-L/usr/lib/."
    echo > expout
    atf-check -s eq:0 -o file:expout -e ignore ${WRAPPER} ${input} \
	|| atf_fail 'XXX no reason'
}

atf_test_case libdir_usr_lib_subdir
libdir_usr_lib_subdir_head() {
    atf_set 'descr' 'XXX autoconverted from libdir-usr-lib-subdir.mk'
}
libdir_usr_lib_subdir_body() {
    wrapper_test_setup cc
    input="-L/usr/lib/i18n"
    echo "-L/usr/lib/i18n" > expout
    atf-check -s eq:0 -o file:expout -e ignore ${WRAPPER} ${input} \
	|| atf_fail 'XXX no reason'
}

atf_init_test_cases() {
    . $(atf_get_srcdir)/setup_common.sh
    atf_add_test_case libdir_usr_lib
    atf_add_test_case libdir_usr_lib_slashdot
    atf_add_test_case libdir_usr_lib_subdir
}
