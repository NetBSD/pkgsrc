# $NetBSD: Makefile,v 1.3 2016/07/27 09:17:41 wiz Exp $

DISTNAME=	lldb-3.8.1.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	lang devel
MASTER_SITES=	http://llvm.org/releases/${PKGVERSION_NOREV}/
#MASTER_SITES=	http://llvm.org/pre-releases/3.8.0/rc1/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lldb.org/
COMMENT=	Next generation, high-performance debugger
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

USE_LANGUAGES=		c c++
USE_CMAKE=		yes
GCC_REQD+=		4.8
PY_PATCHPLIST=		yes

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # compilation failure in 3.8.1 (3.8.0 worked)

CMAKE_ARGS+=	-DLLVM_CONFIG=${LLVM_CONFIG_PATH}
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=gcc
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=g++

CHECK_PORTABILITY_SKIP=	utils/buildit/build_llvm

REPLACE_PERL+=		packages/Python/lldbsuite/test/attic/dotest.pl
REPLACE_PERL+=		scripts/build-llvm.pl
REPLACE_PERL+=		scripts/checkpoint-llvm.pl
REPLACE_PERL+=		scripts/disasm-gdb-remote.pl
REPLACE_PERL+=		scripts/generate-vers.pl
REPLACE_PERL+=		scripts/sed-sources

REPLACE_PYTHON+=	examples/darwin/heap_find/heap.py
REPLACE_PYTHON+=	examples/python/cmdtemplate.py
REPLACE_PYTHON+=	examples/python/crashlog.py
REPLACE_PYTHON+=	examples/python/delta.py
REPLACE_PYTHON+=	examples/python/disasm-stress-test.py
REPLACE_PYTHON+=	examples/python/disasm.py
REPLACE_PYTHON+=	examples/python/gdbremote.py
REPLACE_PYTHON+=	examples/python/globals.py
REPLACE_PYTHON+=	examples/python/lldb_module_utils.py
REPLACE_PYTHON+=	examples/python/lldbtk.py
REPLACE_PYTHON+=	examples/python/mach_o.py
REPLACE_PYTHON+=	examples/python/memory.py
REPLACE_PYTHON+=	examples/python/operating_system.py
REPLACE_PYTHON+=	examples/python/performance.py
REPLACE_PYTHON+=	examples/python/process_events.py
REPLACE_PYTHON+=	examples/python/sbvalue.py
REPLACE_PYTHON+=	examples/python/sources.py
REPLACE_PYTHON+=	examples/python/stacks.py
REPLACE_PYTHON+=	examples/python/symbolication.py
REPLACE_PYTHON+=	examples/python/types.py
REPLACE_PYTHON+=	examples/python/x86_64_linux_target_definition.py
REPLACE_PYTHON+=	examples/python/x86_64_qemu_target_definition.py
REPLACE_PYTHON+=	examples/python/x86_64_target_definition.py
REPLACE_PYTHON+=	packages/Python/lldbsuite/test/attic/tester.py
REPLACE_PYTHON+=	packages/Python/lldbsuite/test/bench.py
REPLACE_PYTHON+=	packages/Python/lldbsuite/test/curses_results.py
REPLACE_PYTHON+=	packages/Python/lldbsuite/test/dosep.py
REPLACE_PYTHON+=	packages/Python/lldbsuite/test/functionalities/plugins/python_os_plugin/operating_system.py
REPLACE_PYTHON+=	packages/Python/lldbsuite/test/functionalities/plugins/python_os_plugin/operating_system2.py
REPLACE_PYTHON+=	packages/Python/lldbsuite/test/redo.py
REPLACE_PYTHON+=	packages/Python/lldbsuite/test/test_runner/test/inferior.py
REPLACE_PYTHON+=	packages/Python/lldbsuite/test/test_runner/test/process_control_tests.py
REPLACE_PYTHON+=	scripts/Python/remote-build.py
REPLACE_PYTHON+=	scripts/buildbot.py
REPLACE_PYTHON+=	scripts/shush
REPLACE_PYTHON+=	scripts/verify_api.py
REPLACE_PYTHON+=	scripts/prepare_bindings.py
REPLACE_PYTHON+=	test/dotest.py
REPLACE_PYTHON+=	third_party/Python/module/pexpect-2.4/FSM.py
REPLACE_PYTHON+=	third_party/Python/module/pexpect-2.4/examples/astat.py
REPLACE_PYTHON+=	third_party/Python/module/pexpect-2.4/examples/bd_client.py
REPLACE_PYTHON+=	third_party/Python/module/pexpect-2.4/examples/bd_serv.py
REPLACE_PYTHON+=	third_party/Python/module/pexpect-2.4/examples/cgishell.cgi
REPLACE_PYTHON+=	third_party/Python/module/pexpect-2.4/examples/chess.py
REPLACE_PYTHON+=	third_party/Python/module/pexpect-2.4/examples/chess2.py
REPLACE_PYTHON+=	third_party/Python/module/pexpect-2.4/examples/chess3.py
REPLACE_PYTHON+=	third_party/Python/module/pexpect-2.4/examples/df.py
REPLACE_PYTHON+=	third_party/Python/module/pexpect-2.4/examples/fix_cvs_files.py
REPLACE_PYTHON+=	third_party/Python/module/pexpect-2.4/examples/ftp.py
REPLACE_PYTHON+=	third_party/Python/module/pexpect-2.4/examples/hive.py
REPLACE_PYTHON+=	third_party/Python/module/pexpect-2.4/examples/monitor.py
REPLACE_PYTHON+=	third_party/Python/module/pexpect-2.4/examples/passmass.py
REPLACE_PYTHON+=	third_party/Python/module/pexpect-2.4/examples/python.py
REPLACE_PYTHON+=	third_party/Python/module/pexpect-2.4/examples/rippy.py
REPLACE_PYTHON+=	third_party/Python/module/pexpect-2.4/examples/script.py
REPLACE_PYTHON+=	third_party/Python/module/pexpect-2.4/examples/ssh_tunnel.py
REPLACE_PYTHON+=	third_party/Python/module/pexpect-2.4/examples/sshls.py
REPLACE_PYTHON+=	third_party/Python/module/pexpect-2.4/examples/topip.py
REPLACE_PYTHON+=	third_party/Python/module/pexpect-2.4/examples/uptime.py
REPLACE_PYTHON+=	third_party/Python/module/progress/progress.py
REPLACE_PYTHON+=	utils/git-svn/convert.py
REPLACE_PYTHON+=	utils/lui/lui.py
REPLACE_PYTHON+=	utils/lui/sandbox.py
REPLACE_PYTHON+=	utils/misc/grep-svn-log.py
REPLACE_PYTHON+=	utils/sync-source/syncsource.py
REPLACE_PYTHON+=	utils/test/disasm.py
REPLACE_PYTHON+=	utils/test/lldb-disasm.py
REPLACE_PYTHON+=	utils/test/llvm-mc-shell.py
REPLACE_PYTHON+=	utils/test/ras.py
REPLACE_PYTHON+=	utils/test/run-dis.py
REPLACE_PYTHON+=	utils/test/run-until-faulted.py

TEST_TARGET=		check-lldb
TEST_ENV+=		LD_LIBRARY_PATH=${WRKDIR}/build/lib

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.  if exists(/usr/include/panel.h)
CMAKE_ARGS+=	-DLLDB_DISABLE_CURSES:BOOL=FALSE
.  else
CMAKE_ARGS+=	-DLLDB_DISABLE_CURSES:BOOL=TRUE
.  endif
.endif

post-extract:
	${RUN} mkdir -p ${WRKDIR}/build

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
DEPENDS+=	llvm-${PKGVERSION_NOREV}{,nb*}:../../lang/llvm
.include "../../lang/llvm/buildlink3.mk"
DEPENDS+=	clang-${PKGVERSION_NOREV}{,nb*}:../../lang/clang
.include "../../lang/clang/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
