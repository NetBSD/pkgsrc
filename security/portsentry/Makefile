# $NetBSD: Makefile,v 1.2 2001/02/17 17:50:03 wiz Exp $
#

DISTNAME=       portsentry-1.0
CATEGORIES=	security
MASTER_SITES=   http://www.psionic.com/tools/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.psionic.com/abacus/portsentry/
COMMENT=	detects and respond to port scans against a target host in real-time

ALL_TARGET=	${LOWER_OPSYS}

post-patch:
	@cd ${WRKSRC};							\
	case ${OPSYS} in						\
	NetBSD)	netbsd=""; solaris="#" ;;				\
	SunOS)	netbsd="#"; solaris="" ;;				\
	esac;								\
	for f in portsentry.conf portsentry_config.h; do		\
		${MV} $$f $$f.prefix;					\
		${SED} -e 's|@PREFIX@|${PREFIX}|g' 			\
			-e 's|@netbsd@|'$$netbsd'|g'			\
			-e 's|@solaris@|'$$solaris'|g'			\
						$$f.prefix > $$f;	\
	done

.include "../../mk/bsd.pkg.mk"
