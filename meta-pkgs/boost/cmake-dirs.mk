# $NetBSD: cmake-dirs.mk,v 1.1 2024/12/26 21:52:31 triaxx Exp $
#
# BOOST_CMAKE_DIRS is the list of directories from ${WRKSRC}/stage/lib that
#	contains CMake files.
#
# This file can be generated after 'make build' by running:
#     cd ${WRKSRC}/stage/lib && find cmake -type d
#
# TODO: implement a target to automatically generate this file

BOOST_CMAKE_DIRS+=	cmake
BOOST_CMAKE_DIRS+=	cmake/boost_date_time-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_exception-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_fiber-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_filesystem-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_graph-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_graph_parallel-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_iostreams-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_json-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_locale-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_thread-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_log-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_log_setup-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_math_c99-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_math_c99f-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_math_c99l-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_mpi-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_math_tr1-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_math_tr1f-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_math_tr1l-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_nowide-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_process-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_program_options-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_random-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_regex-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_serialization-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_wserialization-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_stacktrace_noop-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_stacktrace_basic-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_stacktrace_addr2line-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_system-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_timer-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_prg_exec_monitor-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_test_exec_monitor-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_unit_test_framework-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_type_erasure-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_wave-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_atomic-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_url-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/Boost-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_headers-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_charconv-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_chrono-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_container-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_context-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_contract-${BOOST_VERSION}
BOOST_CMAKE_DIRS+=	cmake/boost_coroutine-${BOOST_VERSION}
