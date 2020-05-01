# $NetBSD: zzz-prepare-tools.mk,v 1.1 2020/05/01 18:37:59 rillig Exp $
#
# This "package" creates wrappers for the platform tools in a temporary
# directory.
#

PKGNAME=	tools-platform-2020.05.01
CATEGORIES=	pkgtools

USE_TOOLS=	chmod sed sh tr

.include "../../mk/bsd.prefs.mk"

PLATFORM_TOOLS!= \
	${SED} -n \
		's,^TOOLS_PLATFORM\.\([^[:space:]]*\)[?]=.*,\1,p' \
		../../mk/tools/tools.*.mk

prepare-platform-tools:
.for tool in ${PLATFORM_TOOLS:O:u}
.  if ${TOOLS_PLATFORM.${tool}:U} && ${TOOLS_PLATFORM.${tool}:[#]} == 1
.    for cmd in ${TOOLS_PLATFORM.${tool}}
.      if ${cmd:M/*}
	@ln -s ${cmd:Q} ${BINDIR:Q}/${tool:Q}
.      elif ${cmd} == "[" || ${cmd:Necho:Nfalse:Ntest:Ntrue} != ${cmd}
# ignore these shell builtins
.      else
	@${ECHO} "Skipping single-word tool "${tool:Q}": "${cmd:Q}
.      endif
.    endfor
.  elif ${TOOLS_PLATFORM.${tool}:U}
	@{ \
		${ECHO} '#! '${SH:Q};					\
		${ECHO} 'exec '${TOOLS_PLATFORM.${tool}:Q}' "$$@"';	\
	} > ${BINDIR:Q}/${tool:Q}
	@${CHMOD} +x ${BINDIR:Q}/${tool:Q}
.  endif
.endfor

.include "../../mk/bsd.pkg.mk"
