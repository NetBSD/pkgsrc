# $NetBSD: Makefile,v 1.33 2004/04/25 05:06:35 snj Exp $
#

DISTNAME=		isakmpd-20030903
PKGREVISION=		2
CATEGORIES=		security net
MASTER_SITES=		ftp://ftp.NetBSD.org/pub/NetBSD/packages/distfiles/LOCAL_PORTS/

MAINTAINER=		itojun@kame.net
COMMENT=		OpenBSD IKE daemon

# this is not compatible with cross build - there's no other way
.if !exists(/usr/include/netinet6/ipsec.h)
PKG_FAIL_REASON+=	"${PKGNAME} requires ipsec-ready ${OPSYS}"
.endif

WRKSRC=			${WRKDIR}/isakmpd

ALL_TARGET=		depend all
USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES

MAKE_ENV+=		BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man

PKG_SYSCONFSUBDIR=	isakmpd

RCD_SCRIPTS=		isakmpd
RCD_SCRIPT_WRK.isakmpd=	${WRKDIR}/isakmpd.sh

pre-configure:
	@${ECHO_MSG} "Fixing references to buildlink directories"
	@for i in ${WRKSRC}/sysdep/netbsd/Makefile.sysdep; do		\
		${MV} $${i} $${i}.unfixed;				\
		${SED} "s+@BUILDLINK_PREFIX.openssl@+${BUILDLINK_PREFIX.openssl}+g" \
			< $${i}.unfixed > $${i};			\
	done
	@${ECHO_MSG} "Fixing references to configuration directory"
	@for i in conf.h policy.h ike_auth.h; do			\
		${MV} ${WRKSRC}/$${i} ${WRKSRC}/$${i}.unfixed;		\
		${SED} "s+/etc/isakmpd+${PKG_SYSCONFDIR}+g"		\
			< ${WRKSRC}/$${i}.unfixed > ${WRKSRC}/$${i};	\
	done
	@${ECHO_MSG} "Fixing manual page references"
	@for i in isakmpd.8 isakmpd.conf.5 isakmpd.policy.5; do		\
		${MV} ${WRKSRC}/$${i} ${WRKSRC}/$${i}.unfixed;		\
		${SED} -e "s+/usr/share/ipsec+${PREFIX}/share/examples+g" \
			-e "s+/etc/isakmpd+${PKG_SYSCONFDIR}+g"		\
			< ${WRKSRC}/$${i}.unfixed > ${WRKSRC}/$${i};	\
	done

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
