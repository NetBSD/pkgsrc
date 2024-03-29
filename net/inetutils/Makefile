# $NetBSD: Makefile,v 1.10 2023/12/31 19:06:15 adam Exp $

DISTNAME=	inetutils-2.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU:=inetutils/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/inetutils/
COMMENT=	GNU network utilities
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	help2man-[0-9]*:../../converters/help2man

AUTO_MKDIRS=		yes
INFO_FILES=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--program-prefix=g
CONFIGURE_ENV+=		inetutils_cv_path_cp=${CP:Q}

LDFLAGS.SunOS+=		-lsocket -lnsl

.for prog in ping ping6 rcp rlogin rsh traceroute
SPECIAL_PERMS+=		bin/g${prog} ${SETUID_ROOT_PERMS}
.endfor

TEST_TARGET=		check

post-install:
.for f in dnsdomainname ftp hostname ifconfig logger ping ping6 \
	rcp rexec rlogin rsh talk telnet tftp traceroute whois
	${LN} -sf ${PREFIX}/bin/g${f} ${DESTDIR}${PREFIX}/${PKGGNUDIR}bin/${f}
	${LN} -sf ${PREFIX}/${PKGMANDIR}/man1/g${f}.1 ${DESTDIR}${PREFIX}/${PKGGNUDIR}${PKGMANDIR}/man1/${f}.1
.endfor
.for f in ftpd inetd rexecd rlogind rshd syslogd talkd telnetd tftpd uucpd
	${LN} -sf ${PREFIX}/libexec/g${f} ${DESTDIR}${PREFIX}/${PKGGNUDIR}libexec/${f}
	${LN} -sf ${PREFIX}/${PKGMANDIR}/man8/g${f}.8 ${DESTDIR}${PREFIX}/${PKGGNUDIR}${PKGMANDIR}/man8/${f}.8
.endfor

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
