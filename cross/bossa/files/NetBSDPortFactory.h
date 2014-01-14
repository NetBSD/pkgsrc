///////////////////////////////////////////////////////////////////////////////
// BOSSA
//
// Copyright (C) 2011-2012 ShumaTech http://www.shumatech.com/
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
///////////////////////////////////////////////////////////////////////////////
#ifndef _NETBSDPORTFACTORY_H
#define _NETBSDPORTFACTORY_H

#include "SerialPort.h"

#include <sys/types.h>
#include <dirent.h>

#include <string>


class NetBSDPortFactory
{
public:
    NetBSDPortFactory();
    virtual ~NetBSDPortFactory();

    virtual std::string begin();
    virtual std::string end();
    virtual std::string next();

    virtual SerialPort::Ptr create(const std::string& name);

private:
    std::string _empty;
    DIR* _dir;
};

#endif // _NETBSDPORTFACTORY_H
