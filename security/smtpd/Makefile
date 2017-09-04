# $NetBSD: Makefile,v 1.25 2017/09/04 18:01:00 wiz Exp $
#

DISTNAME=	smtpd-2.0
PKGREVISION=	3
CATEGORIES=	mail security
MASTER_SITES=	# http://www.netsw.org/net/ip/firewall/proxy/smtpd/

PATCHFILES=	patch-smtpd-2.0-RBL.gz
PATCH_SITES=	ftp://ftp.42.org/pub/OLD/p/

MAINTAINER=	pkgsrc-users@NetBSD.org
# "Obtuse smtpd hasn't been developed further since 1997."
# google for osmtpd
#HOMEPAGE=	http://www.obtuse.com/smtpd.html
COMMENT=	Store and forward SMTP proxy

SPOOL=		/var/spool/smtpd

RCD_SCRIPTS=	smtpfwdd
FILES_SUBST+=	SPOOL=${SPOOL:Q}

# taken directly from the Makefile.
CFLAGS.NetBSD+=	-DUSE_FLOCK -DUSE_MKSTEMP
CFLAGS.DragonFly+=	-DUSE_FLOCK -DUSE_MKSTEMP
CFLAGS.SunOS+=	-DUSE_LOCKF -DNEEDS_FCNTL_H -DNEEDS_STRINGS_H -DBROKEN_SUN_INCLUDES
CFLAGS.IRIX+=	-DGETOPT_EOF -DUSE_FLOCK -DNEEDS_FCNTL_H -DNEEDS_BSTRING_H -DIRIX_BROKEN_INCLUDES
CFLAGS.AIX+=	-DGETOPT_EOF -DUSE_LOCKF -DNEEDS_FCNTL_H -DNEEDS_LOCKF_H -DNEEDS_STRINGS_H -DNEEDS_SELECT_H
OPSYSVARS+=	LD_LIBS
LD_LIBS.SunOS+=	-lnsl -lsocket -lresolv
MAKE_ENV+=	LD_LIBS=${LD_LIBS:Q}

INSTALLATION_DIRS=	sbin share/doc/smtpd share/examples/smtpd
OWN_DIRS=		${SPOOL}/etc

do-install:
	${INSTALL_PROGRAM} -m 500 ${WRKSRC}/smtpd ${DESTDIR}${PREFIX}/sbin/smtpd
	${INSTALL_PROGRAM} -m 500 ${WRKSRC}/smtpfwdd ${DESTDIR}${PREFIX}/sbin/smtpfwdd
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/INSTALL \
	    ${DESTDIR}${PREFIX}/share/doc/smtpd
.for f in antirelay_check_rules_example antispam_check_rules.example \
	    smtpd_check_rules.example
		${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/examples/smtpd
.endfor

.include "../../devel/sysexits/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
