# $NetBSD: Makefile,v 1.4 1997/12/22 07:35:52 hubertf Exp $
# New ports collection makefile for:	tcl8.0
# Version required:	8.0
# Date created:		19 August 1997
# Whom:			jkh
#
# FreeBSD Id: Makefile,v 1.1.1.1 1997/08/20 10:33:35 jkh Exp
#

DISTNAME=	tcl8.0
PKGNAME=	tcl-8.0
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.sunlabs.com/pub/tcl/

MAINTAINER=	jkh@freebsd.org

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ENV+=  PORTSDIR=${PORTSDIR}

MAN1=		tclsh.1
MAN3=		AddErrInfo.3 Alloc.3 AllowExc.3 AppInit.3 AssocData.3 Async.3 BackgdErr.3 Backslash.3 BoolObj.3 CallDel.3 CmdCmplt.3 Concat.3 CrtChannel.3 CrtChnlHdlr.3 CrtCloseHdlr.3 CrtCommand.3 CrtFileHdlr.3 CrtInterp.3 CrtMathFnc.3 CrtObjCmd.3 CrtSlave.3 CrtTimerHdlr.3 CrtTrace.3 DString.3 DetachPids.3 DoOneEvent.3 DoWhenIdle.3 DoubleObj.3 Eval.3 EvalObj.3 Exit.3 ExprLong.3 ExprLongObj.3 FindExec.3 GetIndex.3 GetInt.3 GetOpnFl.3 GetStdChan.3 Hash.3 IntObj.3 Interp.3 LinkVar.3 ListObj.3 Notifier.3 ObjSetVar.3 Object.3 ObjectType.3 OpenFileChnl.3 OpenTcp.3 PkgRequire.3 Preserve.3 PrintDbl.3 RecEvalObj.3 RecordEval.3 RegExp.3 SetErrno.3 SetRecLmt.3 SetResult.3 SetVar.3 Sleep.3 SplitList.3 SplitPath.3 StaticPkg.3 StrMatch.3 StringObj.3 Tcl_Main.3 TraceVar.3 Translate.3 UpVar.3 WrongNumArgs.3
MANN=		Tcl.n after.n append.n array.n bgerror.n binary.n break.n case.n catch.n cd.n clock.n close.n concat.n continue.n eof.n error.n eval.n exec.n exit.n expr.n fblocked.n fconfigure.n fcopy.n file.n fileevent.n filename.n flush.n for.n foreach.n format.n gets.n glob.n global.n history.n http.n if.n incr.n info.n interp.n join.n lappend.n library.n lindex.n linsert.n list.n llength.n load.n lrange.n lreplace.n lsearch.n lsort.n namespace.n open.n package.n pid.n pkgMkIndex.n proc.n puts.n pwd.n read.n regexp.n registry.n regsub.n rename.n resource.n return.n safe.n scan.n seek.n set.n socket.n source.n split.n string.n subst.n switch.n tclvars.n tell.n time.n trace.n unknown.n unset.n update.n uplevel.n upvar.n variable.n vwait.n while.n

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
