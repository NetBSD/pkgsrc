# $NetBSD: test-libpath.sh,v 1.1 2014/09/17 12:40:56 joerg Exp $
#

atf_test_case libpath
libpath_head() {
    atf_set 'descr' 'XXX autoconverted from libpath.mk'
}
libpath_body() {
    wrapper_test_setup cc
    input="${LOCALBASE}/lib/libfoo.la"
    echo "${BUILDLINK_DIR}/lib/libfoo.la" > expout
    atf-check -s eq:0 -o file:expout -e ignore ${WRAPPER} ${input} \
	|| atf_fail 'XXX no reason'
}

atf_test_case libpath_in_define
libpath_in_define_head() {
    atf_set 'descr' 'XXX autoconverted from libpath-in-define.mk'
}
libpath_in_define_body() {
    wrapper_test_setup cc
    input="-DFOO=\"${LOCALBASE}/lib/libfoo.la\""
    echo "-DFOO=\"${LOCALBASE}/lib/libfoo.la\"" > expout
    atf-check -s eq:0 -o file:expout -e ignore ${WRAPPER} ${input} \
	|| atf_fail 'XXX no reason'
}

atf_test_case libpath_shlib
libpath_shlib_head() {
    atf_set 'descr' 'XXX autoconverted from libpath-shlib.mk'
}
libpath_shlib_body() {
    wrapper_test_setup cc
    input="${LOCALBASE}/lib/libfoo.so"
    echo "-L${BUILDLINK_DIR}/lib -lfoo" > expout
    atf-check -s eq:0 -o file:expout -e ignore ${WRAPPER} ${input} \
	|| atf_fail 'XXX no reason'
}

atf_test_case libpath_shmod
libpath_shmod_head() {
    atf_set 'descr' 'XXX autoconverted from libpath-shmod.mk'
}
libpath_shmod_body() {
    wrapper_test_setup cc
    input="${LOCALBASE}/lib/module/foo.so"
    echo "${LOCALBASE}/lib/module/foo.so" > expout
    atf-check -s eq:0 -o file:expout -e ignore ${WRAPPER} ${input} \
	|| atf_fail 'XXX no reason'
}

atf_init_test_cases() {
    . $(atf_get_srcdir)/setup_common.sh
    atf_add_test_case libpath
    atf_add_test_case libpath_in_define
    atf_add_test_case libpath_shlib
    atf_add_test_case libpath_shmod
}
