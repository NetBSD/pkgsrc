@comment $NetBSD: PLIST.java,v 1.1 2003/07/03 16:16:30 drochner Exp $
@unexec ${INSTALL_INFO} --delete %D/info/fastjar.info %D/info/dir
info/fastjar.info
@exec ${INSTALL_INFO} %D/info/fastjar.info %D/info/dir
@unexec ${INSTALL_INFO} --delete %D/info/gcj.info %D/info/dir
info/gcj.info
@exec ${INSTALL_INFO} %D/info/gcj.info %D/info/dir
