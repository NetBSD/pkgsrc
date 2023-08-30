use libc::{c_int,c_ulong};

// socket

pub const FIOSETOWN: c_ulong = 0x8004667c;
pub const SIOCSPGRP: c_ulong = 0x80047308;
pub const FIOGETOWN: c_ulong = 0x4004667b;
pub const SIOCGPGRP: c_ulong = 0x40047309;

// termios

pub const TIOCEXCL: c_ulong = 0x2000740d;
pub const TIOCNXCL: c_ulong = 0x2000740e;
pub const TIOCSCTTY: c_ulong = 0x20007461;
pub const TIOCGPGRP: c_ulong = 0x40047477;
pub const TIOCSPGRP: c_ulong = 0x80047476;
pub const TIOCOUTQ: c_ulong = 0x40047473;
pub const TIOCSTI: c_ulong = 0x80017472;
pub const TIOCGWINSZ: c_ulong = 0x40087468;
pub const TIOCSWINSZ: c_ulong = 0x80087467;
pub const TIOCMGET: c_ulong = 0x4004746a;
pub const TIOCMBIS: c_ulong = 0x8004746c;
pub const TIOCMBIC: c_ulong = 0x8004746b;
pub const TIOCMSET: c_ulong = 0x8004746d;
pub const FIONREAD: c_ulong = 0x4004667f;
pub const TIOCCONS: c_ulong = 0x80047462;
pub const TIOCPKT: c_ulong = 0x80047470;
pub const FIONBIO: c_ulong = 0x8004667e;
pub const TIOCNOTTY: c_ulong = 0x20007471;
pub const TIOCSETD: c_ulong = 0x8004741b;
pub const TIOCGETD: c_ulong = 0x4004741a;
pub const FIONCLEX: c_ulong = 0x20006602;
pub const FIOCLEX: c_ulong = 0x20006601;
pub const FIOASYNC: c_ulong = 0x8004667d;

// sockios

pub const SIOCADDRT: c_ulong = 0x8038720a;
pub const SIOCDELRT: c_ulong = 0x8038720b;
pub const SIOCGIFCONF: c_ulong = 0xc0106926;
pub const SIOCGIFFLAGS: c_ulong = 0xc0906911;
pub const SIOCSIFFLAGS: c_ulong = 0x80906910;
pub const SIOCGIFADDR: c_ulong = 0xc0906921;
pub const SIOCSIFADDR: c_ulong = 0x8090690c;
pub const SIOCGIFDSTADDR: c_ulong = 0xc0906922;
pub const SIOCSIFDSTADDR: c_ulong = 0x8090690e;
pub const SIOCGIFBRDADDR: c_ulong = 0xc0906923;
pub const SIOCSIFBRDADDR: c_ulong = 0x80906913;
pub const SIOCGIFNETMASK: c_ulong = 0xc0906925;
pub const SIOCSIFNETMASK: c_ulong = 0x80906916;
pub const SIOCGIFMETRIC: c_ulong = 0xc0906917;
pub const SIOCSIFMETRIC: c_ulong = 0x80906918;
pub const SIOCGIFMTU: c_ulong = 0xc090697e;
pub const SIOCSIFMTU: c_ulong = 0x8090697f;
pub const SIOCADDMULTI: c_ulong = 0x80906931;
pub const SIOCDELMULTI: c_ulong = 0x80906932;

// modem control lines

pub const TIOCM_LE: c_int = 0x00000001;
pub const TIOCM_DTR: c_int = 0x00000002;
pub const TIOCM_RTS: c_int = 0x00000004;
pub const TIOCM_ST: c_int = 0x00000008;
pub const TIOCM_SR: c_int = 0x00000010;
pub const TIOCM_CTS: c_int = 0x00000020;
pub const TIOCM_CAR: c_int = 0x00000040;
pub const TIOCM_CD: c_int = 0x00000040;
pub const TIOCM_RNG: c_int = 0x00000080;
pub const TIOCM_RI: c_int = 0x00000080;
pub const TIOCM_DSR: c_int = 0x00000100;

extern "C" {
    pub fn ioctl(fildes: c_int, request: c_ulong, ...) -> c_int;
}
