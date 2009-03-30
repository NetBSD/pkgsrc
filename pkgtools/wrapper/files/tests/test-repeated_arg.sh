# $NetBSD: test-repeated_arg.sh,v 1.1.2.2 2009/03/30 01:02:26 schmonz Exp $
#

atf_test_case repeated_arg
repeated_arg_head() {
    atf_set 'descr' 'XXX autoconverted from repeated-arg.mk'
}
repeated_arg_body() {
    input="-L${LOCALBASE}/lib -L${LOCALBASE}/lib"
    echo "-L${BUILDLINK_DIR}/lib" > expout
    atf-check -s eq:0 -o file:expout e ignore 'echowrapper ${input}'
}

atf_init_test_cases() {
    atf_add_test_case repeated_arg
}
