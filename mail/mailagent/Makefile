# $NetBSD: Makefile,v 1.3 2000/03/27 08:54:59 tron Exp $
# FreeBSD: ports/mail/mailagent/Makefile,v 1.28 1999/08/31 06:47:24 mharo Exp
#

DISTNAME=		mailagent-3.0@68
PKGNAME=		mailagent-3.0.68
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:S/by-module/by-authors\/id\/RAM/g}
#MASTER_SITE_SUBDIR=	../../authors/id/RAM

MAINTAINER=	itojun@itojun.org

# be friendly with FreeBSD-ish use of ${PERL5}
PERL5=		${LOCALBASE}/bin/perl

USE_PERL5=	yes
NO_PACKAGE=	"Correct FQDN needs to be hardcoded"
IS_INTERACTIVE=		yes
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS=		-dres \
			-Dperlpath='${PERL5}' \
			-Dutmp='/var/run/utmp' \
			-Dprefix='${PREFIX}' -Dmansrc='${PREFIX}/man/man1' \
			-Dnotifypatches='false'
MAKE_ENV=	PATH=`dirname ${PERL5}`:${PATH}
INSTALL_TARGET=	install install.man

# Note that mailhelp.1 is intentionally left uncompressed as it is referred
# from several other man pages with .so macro.
MAN1=			edusers.1 mailagent.1 maildist.1  \
			maillist.1 mailpatch.1 package.1

pre-extract:
	@if [ `${SH} -c umask` != 0022 ]; then \
	  ${ECHO} "Please set umask to 022 before running make,"; \
	  ${ECHO} "or mailagent will not build successfully."; \
	  ${FALSE}; fi
	@if [ `id -u` = 0 ]; then \
	  ${ECHO} "Do not build mailagent as root or it won't pass the sanity tests."; \
	  ${FALSE}; fi

post-install:
	@${MKDIR} ${PREFIX}/share/examples/mailagent
	@${MKDIR} ${PREFIX}/share/examples/mailagent/misc
	${CP} -pR ${WRKSRC}/misc/* ${PREFIX}/share/examples/mailagent/misc
	@${LN} -fs ${PREFIX}/lib/mailagent/examples ${PREFIX}/share/examples/mailagent/agent

.include "../../mk/bsd.pkg.mk"
