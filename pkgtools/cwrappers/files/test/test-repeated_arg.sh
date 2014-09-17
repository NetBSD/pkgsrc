# $NetBSD: test-repeated_arg.sh,v 1.1 2014/09/17 12:40:56 joerg Exp $
#

atf_test_case repeated_arg
repeated_arg_head() {
    atf_set 'descr' 'XXX autoconverted from repeated-arg.mk'
}
repeated_arg_body() {
    wrapper_test_setup cc
    input="-L${LOCALBASE}/lib -L${LOCALBASE}/lib"
    echo "-L${BUILDLINK_DIR}/lib" > expout
    atf-check -s eq:0 -o file:expout -e ignore ${WRAPPER} ${input} \
	|| atf_fail 'XXX no reason'
}

atf_init_test_cases() {
    . $(atf_get_srcdir)/setup_common.sh
    atf_add_test_case repeated_arg
}
