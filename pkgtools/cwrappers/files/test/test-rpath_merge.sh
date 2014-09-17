# $NetBSD: test-rpath_merge.sh,v 1.1 2014/09/17 12:40:56 joerg Exp $
#

atf_test_case rpath_merge
rpath_merge_head() {
    atf_set 'descr' 'XXX autoconverted from rpath-merge.mk'
}
rpath_merge_body() {
    wrapper_test_setup cc
    input="${COMPILER_RPATH_FLAG:S/,$//} -Wl,${LOCALBASE}/lib:${LOCALBASE}/lib/foo"
    case "${_USE_RPATH}" in
    [yY][eE][sS])
        echo "${COMPILER_RPATH_FLAG}${LOCALBASE}/lib ${COMPILER_RPATH_FLAG}${LOCALBASE}/lib/foo" > expout
        ;;
    *)
        echo > expout
        ;;
    esac
    atf-check -s eq:0 -o file:expout -e ignore ${WRAPPER} ${input} \
	|| atf_fail 'XXX no reason'
}

atf_init_test_cases() {
    . $(atf_get_srcdir)/setup_common.sh
    atf_add_test_case rpath_merge
}
