# $NetBSD: Makefile,v 1.18 2006/07/20 20:07:13 jlam Exp $
#

DISTNAME=	smtpd-2.0
PKGREVISION=	3
CATEGORIES=	mail security
MASTER_SITES=	ftp://ftp.obtuse.com/pub/smtpd/

PATCHFILES=	patch-smtpd-2.0-RBL.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.obtuse.com/smtpd.html
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

INSTALLATION_DIRS=	sbin
OWN_DIRS=		${SPOOL}

do-install:
	${INSTALL_DATA_DIR} ${SPOOL}/etc
	${INSTALL} -m 500 ${WRKSRC}/smtpd ${PREFIX}/sbin/smtpd
	${INSTALL} -m 500 ${WRKSRC}/smtpfwdd ${PREFIX}/sbin/smtpfwdd
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/smtpd
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/smtpd
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/smtpd
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/smtpd
.for f in antirelay_check_rules_example antispam_check_rules.example \
	    smtpd_check_rules.example
		${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/examples/smtpd
.endfor

.include "../../mk/bsd.pkg.mk"
